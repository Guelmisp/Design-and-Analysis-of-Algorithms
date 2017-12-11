//  Created by Miguel Pessoa on 11/27/17.
//  Copyright © 2017 Miguel Pessoa. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <chrono>

using namespace std::chrono;

void balencedJobBounds(double devicesNumber, std::vector<double> S, std::vector<double> V, double usersNumber, double thinkTime) {
    double davg = 0.0;
    double d = 0.0;
    double dmax = 0.0;
    
    std::vector <double> D(devicesNumber,0);
    
    std::vector <double> auxMin(2,0);
    std::vector <double> xMin(devicesNumber+1,0);
    std::vector <double> xMax(devicesNumber+1,0);
    std::vector <double> rMin(devicesNumber+1,0);
    std::vector <double> rMax(devicesNumber+1,0);
    
    std::vector <double> xiMin(devicesNumber+1,0);
    std::vector <double> xiMax(devicesNumber+1,0);
    std::vector <double> uiMin(devicesNumber+1,0);
    std::vector <double> uiMax(devicesNumber+1,0);
    
    for (int i = 0; i < devicesNumber; i++) {
        D[i] = S[i] * V[i];
        d += D[i];
    }
    davg = d/devicesNumber;
    dmax = *std::max_element(D.begin(), D.end());
    
    for (int n = 1; n <= usersNumber; n++) {
        auxMin[0] = n*dmax-thinkTime;
        auxMin[1] = d + ((n-1)*(davg/(1+thinkTime/d)));
        rMin[n] = *std::min_element(auxMin.begin(), auxMin.end());
        if (n == 1)
            rMax[n] = d;
        else
            rMax[n] = d + (n-1)*(dmax/(1+thinkTime/((n-1)*d)));
        
        xMin[n] = n/(thinkTime+rMax[n]);
        xMax[n] = n/(thinkTime+rMin[n]);
        
        std::cout << xMin[n] << " " << xMax[n] << std::endl;
        
        for(int i = 1; i <= usersNumber; i++) {
            xiMin[i] = xMin[i]*V[i];
            xiMax[i] = xMin[i]*V[i];
            uiMin[i] = xMin[i]*D[i-1];
            uiMax[i] = xMax[i]*D[i-1];
        }
        
    }
    
}

void mvaApproximated(float devicesNumber, std::vector<double> S, std::vector<double> V, double usersNumber, float thinkTime, float error, int type) {
    float R = 0.0, X0= 0.0;
    int count = 0;
    double initial = usersNumber/devicesNumber;
    
    std::vector <float> Ui;
    std::vector <float> Xi;
    std::vector <double> Ri(devicesNumber,0);
    std::vector <double> Qold(devicesNumber, initial);
    std::vector <double> max(devicesNumber);
    
    std::vector <double> Q(devicesNumber, initial);
    for (int j = 0; j < devicesNumber; j ++ ) {
        std::cout << "Q["<< j << "]: " << Q[j] << " ";
    }
    for (int i = 0; i < devicesNumber; i++) {
        max[i] = std::abs(Qold[i] - X0*Ri[i]*V[i]);
    }
    
    while (*std::max_element(max.begin(), max.end()) > error) {
        
        std::cout << "Iteration: " << ++count << std::endl;
        
        std::cout << "Response Time - Ri: " << std::endl;
        for (int j = 0; j < devicesNumber; j ++) {
            if (type == 1)
                Ri[j] = S[j] + (S[j] * ((usersNumber-1)/usersNumber) * Q[j]);
            else
                Ri[j] = S[j];
            
            std::cout << "R[" << j << "]: " << Ri[j] << " ";
            
            R += Ri[j] * V[j];
        }
        
        std::cout << std::endl;
        std::cout << "System Response Time (R):  " << R << std::endl;
        
        X0 = usersNumber/(R+thinkTime);
        std::cout << "System Throughput: " << X0 << std::endl;
        
        std::cout << "Queue Lengths: " << std::endl;
        for (int j = 0; j < devicesNumber; j++) {
            Q[j] = X0*V[j]*Ri[j];
            max[j] = std::abs(Qold[j] - Q[j]);
            Qold[j] = Q[j];
            std::cout << "Q["<< j << "]: " << Q[j] << " ";
            
        }
        std::cout << std::endl << std::endl;
        R = 0;
    }
}


void mva(int devicesNumber, std::vector<double> S, std::vector<double> V, int usersNumber, float thinkTime, int type) {
    
    float R = 0.0, X0;
    
    std::vector <float> Ui;
    std::vector <float> Xi;
    std::vector <float> Ri(devicesNumber);
    std::vector <float> Q(devicesNumber);
    
    for (int i = 0; i < usersNumber; i++) {
        
        std::cout << "Iteration: " << i+1 << std::endl;
        
        std::cout << "Response Time - Ri: " << std::endl;
        for (int j = 0; j < devicesNumber; j ++) {
            if (type == 1)
                Ri[j] = S[j] + (S[j]*Q[j]);
            else
                Ri[j] = S[j];
            
            std::cout << "R[" << j << "]: " << Ri[j] << " ";
            
            R += Ri[j] * V[j];
        }
        std::cout << std::endl;
        std::cout << "System Response Time (R):  " << R << std::endl;
        
        X0 = (i+1)/(R+thinkTime);
        std::cout << "System Throughput: " << X0 << std::endl;
        std::cout << "Queue Lengths: " << std::endl;
        for (int j = 0; j < devicesNumber; j++) {
            Q[j] = X0*V[j]*Ri[j];
            std::cout << "Q["<< j << "]: " << Q[j] << " ";
        }
        
        std::cout << std::endl << std::endl;
        R = 0;
    }
    
    
}

int main(int argc, const char * argv[]) {
    
    /*
     input example MVA/MVA Approximated:
     [Number of Users, Think Time, Number of Divices, Si..N, Vi...N]
     20 4 3 0.3 0.2 0.125 10 5 16
     */
    
    
    /* 1 A
     20 24 3 0.08 0.04 0.03676 55 80 136
     */
    high_resolution_clock::time_point t1;
    high_resolution_clock::time_point t2;
    high_resolution_clock::time_point t3;
    high_resolution_clock::time_point t4;
    high_resolution_clock::time_point t5;
    high_resolution_clock::time_point t6;
    
    float N, Z, M;
    float input;
    float error = 0.01;
    
    std::vector<double> Vi;
    std::vector <double> Si;
    
    std::cout << "Provide the values of N Z M S0...N V0...N:" << std::endl;
    std::cin >> N >> Z >> M;
    
    for (int i = 0; i < M; i++)  {
        std::cin >> input;
        Si.push_back(input);
    }
    
    for (int i = 0; i < M; i++)  {
        std::cin >> input;
        Vi.push_back(input);
    }
    
    t1 = high_resolution_clock::now();
    mva(M, Si, Vi, N, Z, 1);
    t2 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>( t2 - t1 ).count();
    
    std::cout << "\n";
    
    t3 = high_resolution_clock::now();
    mvaApproximated(M, Si, Vi, N, Z, error, 1);
    t4 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>( t4 - t3 ).count();
    
    std::cout << "\n";
    
    t5 = high_resolution_clock::now();
    balencedJobBounds(M, Si, Vi, N, Z);
    t6 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>( t6 - t5 ).count();
    
    std::cout << "\n\nExecution Time in (milliseconds): " << std::endl;
    std::cout << "MVA : " << duration1 << std::endl;
    std::cout << "MVA Approximated: " << duration2 << std::endl;
    std::cout << "Balenced Job Bounds: " << duration3 << std::endl;
    
    return 0;
}
