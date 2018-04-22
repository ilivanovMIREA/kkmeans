//#include <dlib/gui_widgets.h>
//#include <dlib/image_transforms.h>

#include <cmath>
#include <iostream>
#include <vector>

#include <dlib/clustering.h>
#include <dlib/rand.h>

using namespace std;
using namespace dlib;

typedef matrix<double,2,1> sample_type;
typedef radial_basis_kernel<sample_type> kernel_type;

int main(int argc, char* argv[])
{
    if (argc > 1)
    {

        //количество кластеров
        int n = (int)(*argv[1]) - 48;
        
        dlib::rand rnd;
        //std::vector<double> labels;
        std::vector<sample_type> samples;
        std::vector<sample_type> initial_centers;
        
        kcentroid<kernel_type> kc(kernel_type(0.1),0.01, 8);
        kkmeans<kernel_type> test(kc);

        //для визуализации
        //std::vector<perspective_window::overlay_dot> points;
        
        for(std::string line; std::getline(std::cin, line);)
        {
            sample_type m;
            auto start = 0;
            auto stop = line.find_first_of(";");
            
            m(0) = std::stod (line.substr(start, stop - start)) ;
            start = stop + 1;
            m(1) = std::stod (line.substr(start));
            
            //dlib::vector<double> val(m(0),m(1),0);
            //rgb_pixel color = colormap_jet(7,0,20);

            //points.push_back(perspective_window::overlay_dot(val, color));        
            samples.push_back(std::move(m));
        }

        //разбиение на кластеры
        test.set_number_of_centers(n);
        pick_initial_centers(n, initial_centers, samples, test.get_kernel());
        test.train(samples,initial_centers);

        //вывод данных
        for (unsigned long i = 0; i < samples.size(); ++i)
        {
            cout<< samples[i](0)<< ";" << samples[i](1)<< ";"<< "cluster" << test(samples[i]) << "\n ";
        }

        // визуализация 
        /*perspective_window win;
        win.set_title("perspective_window 3D point cloud");
        win.add_overlay(points);
        win.wait_until_closed();*/
    } 
    else
    {
        cout << "Not arguments" << endl;
    }

    return 0;    
}
