//    Implementation by Tyler Downey
//    Cube3D Class
//    Cube that can be rendered to screen

#include <iostream>
#include <cstring>
#include "../h/Cube3D.h"
#include "../h/Transform3D.h"

using namespace std;

const pair<int,int> edges[12] = {{0,1},{0,2},{0,4},{1,3},{1,5},{2,3},{2,6},{3,7},{4,5},{4,6},{5,7},{6,7}};
const double normals[6][3] = {{1, 0, 0}, {0, -1, 0}, {0, 0, 1}, {-1, 0, 0}, {0, 1, 0}, {0, 0, -1}};
const int face_edges[6][4] = {{1, 2, 9, 6}, {5, 6, 11, 7}, {0, 1, 5, 3}, {3, 4, 10, 7}, {0, 2, 8, 4}, {8, 9, 11, 10}, };
const double PERSPECTIVE = 0.05;

double applyPerspective(double x, double z, double origin) {
    return x; // Turns perspective off
    double toreturn = x - origin;
    toreturn = toreturn / (1 + (z * PERSPECTIVE));
    toreturn += origin;
    return toreturn;
}

Cube3D::Cube3D(int edge) {
    edge_length = edge;
    x = 0;
    y = 0;
    z = 0;
    for(int i = 0; i < 8; i++) {
        vertices[i][0] = edge / 2.0 * ((i%2==0)?1:-1);
        vertices[i][1] = edge / 2.0 * ((i%4<2)?1:-1);
        vertices[i][2] = edge / 2.0 * ((i/4==0)?1:-1);
    }
    for (int i = 0; i < 6; i++) {
        faces[i] = BLACK_CHAR;
    }
};

void Cube3D::setFace(int face, char c) {
    faces[face] = c;
};

int getWindingNumber(double* testpoint, double* p1, double* p2) {
    if (testpoint[0] > max(p1[0], p2[0])) return 0;
    if (testpoint[1] > max(p1[1], p2[1])) return 0;
    if (testpoint[1] < min(p1[1], p2[1])) return 0;
    if (p1[0] == p2[0]) return (p1[1] > p2[1]) ? -1 : 1;
    double intersect;
    double m;
    m = (p2[1] - p1[1]) / (p2[0] - p1[0]);
    intersect = (testpoint[1] - (p1[1] - m * p1[0])) / m;
    if (testpoint[0] < intersect) return (m > 0) ? 1 : -1;
    return 0;
};

bool pointInRegion(double* testpoint, double* p1, double* p2, double* p3, double* p4) {
    int wnum = 0;
    wnum += getWindingNumber(testpoint, p1, p2);
    wnum += getWindingNumber(testpoint, p2, p3);
    wnum += getWindingNumber(testpoint, p3, p4);
    wnum += getWindingNumber(testpoint, p4, p1);
    return wnum != 0;
}

void fillRegion(double* p1, double* p2, double* p3, double* p4, StringScreen* s, char c) {
    double max_x = max(p1[0], max(p2[0], max(p3[0], p4[0])));
    double min_x = min(p1[0], min(p2[0], min(p3[0], p4[0])));
    double max_y = max(p1[1], max(p2[1], max(p3[1], p4[1])));
    double min_y = min(p1[1], min(p2[1], min(p3[1], p4[1])));
    double i[3];
    for (int x = min_x; x < max_x; x++) {
        for (int y = min_y; y < max_y; y++) {
            i[0] = (double)x + 0.5;
            i[1] = (double)y + 0.5;
            if (pointInRegion( i, p1, p2, p3, p4)) {
                s->setchar(x, y, c);
            }
        }
    }
}


// Render to StringScreen
void Cube3D::render(StringScreen* screen) {
    double* point1;
    double* point2;
    double* point3;
    double* point4;
    double* normal;
    int edge1;
    int edge2;
    int v1;
    int v2;
    int v3;
    int v4;
    bool edge_drawn[12] = {false};
    
    for(int i = 0; i < 6; i ++) {
        normal = transform.apply(normals[i][0] * edge_length / 2, normals[i][1] * edge_length / 2, normals[i][2] * edge_length / 2);
        if( normal[2] >= 0 ) continue;

        v1 = (edges[face_edges[i][0]].first==edges[face_edges[i][1]].first || edges[face_edges[i][0]].first == edges[face_edges[i][1]].second)? edges[face_edges[i][0]].first: edges[face_edges[i][0]].second;
        v2 = (v1 == edges[face_edges[i][1]].first) ? edges[face_edges[i][1]].second : edges[face_edges[i][1]].first;
        v3 = (v2 == edges[face_edges[i][2]].first) ? edges[face_edges[i][2]].second : edges[face_edges[i][2]].first;
        v4 = (v3 == edges[face_edges[i][3]].first) ? edges[face_edges[i][3]].second : edges[face_edges[i][3]].first;

        point1 = transform.apply(vertices[v1][0], vertices[v1][1], vertices[v1][2]);
        point2 = transform.apply(vertices[v2][0], vertices[v2][1], vertices[v2][2]);
        point3 = transform.apply(vertices[v3][0], vertices[v3][1], vertices[v3][2]);
        point4 = transform.apply(vertices[v4][0], vertices[v4][1], vertices[v4][2]);
        
        point1[0] += x;
        point1[1] = point1[1] / 2 + y;
        point2[0] += x;
        point2[1] = point2[1] / 2 + y;
        point3[0] += x;
        point3[1] = point3[1] / 2 + y;
        point4[0] += x;
        point4[1] = point4[1] / 2 + y;
        
        fillRegion(point1, point2, point3, point4, screen, faces[i]);
        delete point1;
        delete point2;
        delete point3;
        delete point4;


        //screen->setchar(normal[0] + x, normal[1] / 2 + y, (i%3==0)?R_CHAR:(i%3==1)?C_CHAR:L_CHAR);
        
        for(int j = 0; j < 4; j++) {
            if(edge_drawn[face_edges[i][j]]) continue;
            edge_drawn[face_edges[i][j]] = true;
            edge1 = edges[face_edges[i][j]].first;
            edge2 = edges[face_edges[i][j]].second;
            point1 = transform.apply(vertices[edge1][0], vertices[edge1][1], vertices[edge1][2]);
            point2 = transform.apply(vertices[edge2][0], vertices[edge2][1], vertices[edge2][2]);
            
            screen->drawline(point1[0] + x, point1[1] / 2 + y, point2[0] + x, point2[1] / 2 + y, BLACK_CHAR); // faces[i]);
            delete point1;
            delete point2;
        }
        delete normal;
        
    }

    /* Wireframe render
    for(int i = 0; i < 12; i++) {
        edge1 = edges[i].first;
        edge2 = edges[i].second;
        point1 = transform.apply(vertices[edge1][0], vertices[edge1][1], vertices[edge1][2]);
        point2 = transform.apply(vertices[edge2][0], vertices[edge2][1], vertices[edge2][2]);
        screen.drawline(applyPerspective(point1[0] + x, point1[2], screen.getwidth() / 2), applyPerspective(point1[1] / 2 + y, point1[2], screen.getheight() / 2), applyPerspective(point2[0] + x, point2[2], screen.getwidth() / 2), applyPerspective(point2[1] / 2 + y, point2[2], screen.getheight() / 2));
    }
    */
    
};

// Size on screen
int Cube3D::getWidth() const {
    return 0;
};

int Cube3D::getHeight() const {
    return 0;
};

void Cube3D::setPosition(double px, double py, double pz) {
    x = px;
    y = py;
    z = pz;
};

double* Cube3D::getPosition() const {
    double* toreturn = new double[3];
    toreturn[0] = x;
    toreturn[1] = y;
    toreturn[2] = z;
    return toreturn;
};