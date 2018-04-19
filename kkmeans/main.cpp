
#include <dlib/gui_widgets.h>
#include <dlib/image_transforms.h>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <dlib/svm_threaded.h>
#include <dlib/clustering.h>
#include <dlib/rand.h>

using namespace std;
using namespace dlib;

typedef matrix<double,2,1> sample_type;
typedef radial_basis_kernel<sample_type> kernel_type;


// ----------------------------------------------------------------------------------------

int main()
{

    std::vector<double> labels;
    std::vector<sample_type> samples;
    std::vector<sample_type> initial_centers;
    sample_type m;

    typedef one_vs_one_trainer<any_trainer<sample_type> > ovo_trainer;
    ovo_trainer trainer;            
 
 
    typedef polynomial_kernel<sample_type> poly_kernel;
    typedef radial_basis_kernel<sample_type> rbf_kernel;

    // make the binary trainers and set some parameters
    krr_trainer<rbf_kernel> rbf_trainer;
    svm_nu_trainer<poly_kernel> poly_trainer;
    poly_trainer.set_kernel(poly_kernel(0.1, 1, 2));
    rbf_trainer.set_kernel(rbf_kernel(0.1));


    trainer.set_trainer(rbf_trainer);
    trainer.set_trainer(poly_trainer, 1, 2);
    
    one_vs_one_decision_function<ovo_trainer, 
        decision_function<poly_kernel>,  // This is the output of the poly_trainer
        decision_function<rbf_kernel>    // This is the output of the rbf_trainer
        >  df;


    // load the function back in from disk and store it in df3.  
    deserialize("df.dat") >> df;
   
    std::vector<perspective_window::overlay_dot> points;
    for(std::string line; std::getline(std::cin, line);)
    {
        auto start = 0;
        auto stop = line.find_first_of(";");
        
        sample_type m;
        m(0) = std::stod (line.substr(start, stop - start)) ;
        start = stop + 1;
        m(1) = std::stod (line.substr(start));
            

        dlib::vector<double> val(m(0),m(1),0);
        rgb_pixel color = colormap_jet(7,0,20);

        // And add the point to the list of points we will display
        points.push_back(perspective_window::overlay_dot(val, color));
        //cout << "predicted label: "<< df3(m)  << ", true label: "<< "  " << endl;

        // add this sample to our set of samples we will run k-means 
        samples.push_back(std::move(m));
        labels.push_back(df(m));
    }

    randomize_samples(samples, labels);
    for(auto i=0; i<samples.size(); ++i)
        cout<< samples[i](0) << ";" << samples[i](1)<< ";" << "cluster"<< df(samples[i]) << endl;


    //cout << "samples.size(): "<< samples.size() << endl;
    perspective_window win;
    win.set_title("perspective_window 3D point cloud");
    win.add_overlay(points);
    win.wait_until_closed();
}

//  ----------------------------------------------------------------------------

