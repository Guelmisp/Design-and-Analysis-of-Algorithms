#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <math.h>

/*Smallest distance from a given set of points*/
struct Point{
    int x; 
    int y;
};

double dist(Point p1, Point p2) {
    return sqrt( (p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

vector <Point> smallerDistanceBF (Point P[], int n) {
    double menorDistancia = std::numeric_limits<double>::infinity();
    vector <Point> points(2);

    for (int  i = 0; i < n, i ++) {
        for (int  j = 0; i < n, i ++) {
            Point p = P[i];
            Point q = P[j];

            if (dist(p, q) < menorDistancia) {
                menorDistancia = dist(p, q);
                points[0] = p;
                points[1] = q;
            }
        }
    }
    return points;

}

int main() {
    Point P[] = {{2, 3}, {12, 30}, {40, 50}, {5, 1}, {12, 10}, {3, 4}};
    int n = sizeof(P) / sizeof(P[0]);
    vector <Point> solution = smallerDistanceBF(P, n);
    cout << solution[0] <<  endln << solution[1] endln;
    cout << dist(solution[0], solution[1]);

    return 0;
}