#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

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

/*
Mean-Value Analysis (MVA) Algorithm
 inputs:
    devicesNumber = number of Divices
    S = service time per visit to the ith device
    V = number of visits to the ith device
    usersNumber = number of users
    thinkTime = think time (Z)
    Type == 1 - > Fixed Capacity
    Type == 0 - > Delay Centers
*/

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
    
    mva(M, Si, Vi, N, Z, 1);
    mvaApproximated(M, Si, Vi, N, Z, error, 1);
    
    return 0;
}

