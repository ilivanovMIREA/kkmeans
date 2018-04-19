// The contents of this file are in the public domain. See LICENSE_FOR_EXAMPLE_PROGRAMS.txt
/*

    This is an example illustrating the use of the perspective_window tool
    in the dlib C++ Library.  It is a simple tool for displaying 3D point 
    clouds on the screen.

*/

#include <dlib/gui_widgets.h>
#include <dlib/image_transforms.h>
#include <cmath>
#include <iostream>
#include <vector>

#include <dlib/clustering.h>
#include <dlib/rand.h>

using namespace std;
using namespace dlib;

/*
void generate_data(
        std::vector<sample_type>& samples,
        std::std::vector<double>& labels
)
{
    dlib::rand rnd;
    auto gen = [$rnd, &samples,&labels](long num, double radius,
                                        int label,
                                        double translate_x = 0.0,
                                        double trandlate_y = 0.0)
    {
        for (long i = 0; i < num; ++i)
        {
            double sign = 1;
            if (rnd.get_random_double() < 0.5)
                sign = -1;
            m(0) = 2*radius*rnd.get_random_double()-radius;
            m(1) = sign*sqrt(radius*radius - m(0)*m(0));

            // translate this point away from the origin
            m(0) += translate_x;
            m(1) += trandlate_y;

            // add this sample to our set of samples we will run k-means 
            samples.push_back(std::move(m));
            labels.push_back(label);
        }
    }
}*/

// ----------------------------------------------------------------------------------------

int main()
{
    
    typedef matrix<double,2,1> sample_type;
    typedef radial_basis_kernel<sample_type> kernel_type;
    kcentroid<kernel_type> kc(kernel_type(0.1),0.01, 8);
    kkmeans<kernel_type> test(kc);


    std::vector<double> labels;
    std::vector<sample_type> samples;
    std::vector<sample_type> initial_centers;
    sample_type m;
    dlib::rand rnd;

    // we will make 50 points from each class
    const long num = 50;

    // make some samples near the origin
    double radius = 0.5;
    // Let's make a point cloud that looks like a 3D spiral.
    std::vector<perspective_window::overlay_dot> points;

    auto gen = [&rnd, &samples, &labels, &points](long num, double radius,
                                        int label,
                                        double translate_x = 0.0,
                                        double trandlate_y = 0.0)
    {
        
        for (long i = 0; i < num; ++i)
        {
            sample_type m;
            double sign = 1;
            if (rnd.get_random_double() < 0.5)
                sign = -1;
            
            m(0) = 2*radius*rnd.get_random_double()-radius;
            m(1) = sign*sqrt(radius*radius - m(0)*m(0));
            

            // translate this point away from the origin
            m(0) += translate_x;
            m(1) += trandlate_y;
            cout << m(0) << " " << m(1) << endl;

            dlib::vector<double> val(m(0),m(1),0);
            rgb_pixel color = colormap_jet(i,0,20);

            // And add the point to the list of points we will display
            points.push_back(perspective_window::overlay_dot(val, color));

            // add this sample to our set of samples we will run k-means 
            samples.push_back(std::move(m));
            labels.push_back(label);
        };
    };

    gen(60, radius, 1);
    gen(70, 10.0, 2);
    //gen(80, 4.0, 3,25.0,25.0);

    // tell the kkmeans object we made that we want to run k-means with k set to 3. 
    // (i.e. we want 3 clusters)
    test.set_number_of_centers(3);

    // You need to pick some initial centers for the k-means algorithm.  So here
    // we will use the dlib::pick_initial_centers() function which tries to find
    // n points that are far apart (basically).  
    pick_initial_centers(3, initial_centers, samples, test.get_kernel());

    // now run the k-means algorithm on our set of samples.  
    test.train(samples,initial_centers);

    // now loop over all our samples and print out their predicted class.  In this example
    // all points are correctly identified.
    for (unsigned long i = 0; i < samples.size()/3; ++i)
    {
        cout << test(samples[i]) << " ";
        cout << test(samples[i+num]) << " ";
        cout << test(samples[i+2*num]) << "\n";
    }

    // Now print out how many dictionary vectors each center used.  Note that 
    // the maximum number of 8 was reached.  If you went back to the kcentroid 
    // constructor and changed the 8 to some bigger number you would see that these
    // numbers would go up.  However, 8 is all we need to correctly cluster this dataset.
    cout << "num dictionary vectors for center 0: " << test.get_kcentroid(0).dictionary_size() << endl;
    cout << "num dictionary vectors for center 1: " << test.get_kcentroid(1).dictionary_size() << endl;
    cout << "num dictionary vectors for center 2: " << test.get_kcentroid(2).dictionary_size() << endl;


    // Finally, we can also solve the same kind of non-linear clustering problem with
    // spectral_cluster().  The output is a vector that indicates which cluster each sample
    // belongs to.  Just like with kkmeans, it assigns each point to the correct cluster.
    std::vector<unsigned long> assignments = spectral_cluster(kernel_type(0.1), samples, 3);
    cout << mat(assignments) << endl;
    
    
    /*dlib::rand rnd;
    for (double i = 0; i < 20; i+=0.001)
    {
        // Get a point on a spiral
        dlib::vector<double> val(sin(i),cos(i),i/4);

        // Now add some random noise to it
        dlib::vector<double> temp(rnd.get_random_gaussian(),
                                  rnd.get_random_gaussian(),
                                  rnd.get_random_gaussian());
        val += temp/20;

        // Pick a color based on how far we are along the spiral
        rgb_pixel color = colormap_jet(i,0,20);

        // And add the point to the list of points we will display
        points.push_back(perspective_window::overlay_dot(val, color));
    }
*/

    // Now finally display the point cloud.
    perspective_window win;
    win.set_title("perspective_window 3D point cloud");
    win.add_overlay(points);
    win.wait_until_closed();
}

//  ----------------------------------------------------------------------------

