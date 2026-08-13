// DAQ coincidence simulation for MiniPET
// Low-level electronics logic (C++)

#include <iostream>     // std::cout
#include <random>       // random number generation
#include <cmath>        // std::abs
#include <fstream>      // file output

int main() {

    std::ofstream file("daq_efficiency.txt");

    // number of annihilation events
    const int N_EVENTS = 10000;

    // detector timing resolution (ns)
    const double sigma_time = 0.3;

    // random engine (fixed seed -> reproducibility)
    std::default_random_engine generator(42);

    // gaussian timing jitter for MPPC signals
    std::normal_distribution<double> time_dist(0.0, sigma_time);

    // sweep coincidence window values (ns)
    for (double coincidence_window = 0.5;
         coincidence_window <= 2.0;
         coincidence_window += 0.25) {

        int accepted = 0;   // reset counter for THIS window

        // simulate DAQ processing of events
        for (int i = 0; i < N_EVENTS; i++) {

            // simulated detection times in two detectors
            double t1 = time_dist(generator);
            double t2 = time_dist(generator);

            // coincidence condition (hardware logic)
            if (std::abs(t1 - t2) < coincidence_window) {
                accepted++;
            }
        }

        // detection efficiency
        double efficiency = static_cast<double>(accepted) / N_EVENTS;

        // write file
        file << coincidence_window << " "
            << accepted << " "
            << efficiency << "\n";



        // output results (DAQ readout)
        std::cout << "Window: " << coincidence_window << " ns | "
                  << "Accepted: " << accepted << " | "
                  << "Efficiency: " << efficiency << std::endl;
    }

    file.close();
    return 0;
}
