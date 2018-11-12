#pragma once
#include <math.h>

struct mat4 {
    //member 2D float array
    float m[4][4];

    //constructors
    mat4(){}
    mat4(float v){
        for(int i = 0; i < 4; i++) {
            this->m[i][i] = v;
        }
    }
    mat4(float m[4][4]) {
        for(int i = 0; i < 4; i ++) {
            for(int j = 0; j < 4; j++) {
                this->m[i][j] = m[i][j];
            }
        }
    }

    mat4(mat4& m){
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                this->m[i][j] = m.m[i][j];
            }
        }
    }

    //methods that alter the state of this matrix
    void add(mat4 m){
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                this->m[i][j] += m.m[i][j];
            }
        }
    }
    void subtract(mat4 m){
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                this->m[i][j] -= m.m[i][j];
            }
        }
    }
    void multiply(mat4 m){
        mat4 matTemp;
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                int tempSum = 0;
                for(int k = 0; k < 4; k++) {
                    tempSum += (this->m[i][k]*m.m[k][j]);
                }
                matTemp.m[i][j] = tempSum;
            }
        }
        for(int i = 0; i < 4; i++) {
            for(int j = 0; j < 4; j++) {
                this->m[i][j] = matTemp.m[i][j];
            }
        }
    }
    

    //methods for ROTATION transformation
    void rotateX(float degrees) {
        float angle = degToRad(degrees);
        float rotXarray[4][4] = {{1, 0, 0, 0}, {0, cos(angle), -sin(angle), 0}, {0, sin(angle), cos(angle), 0}, {0, 0, 0, 1}};
        mat4 rotX(rotXarray);
        this->multiply(rotX);
    }
    void rotateY(float degrees) {
        float angle = degToRad(degrees);
        float rotYarray[4][4] = {{cos(angle), 0, sin(angle), 0}, {0, 1, 0, 0}, {-sin(angle), 0, cos(angle), 0}, {0, 0, 0, 1}};
        mat4 rotY(rotYarray);
        this->multiply(rotY);
    }
    void rotateZ(float degrees) {
        float angle = degToRad(degrees);
        float rotZarray[4][4] = {{cos(angle), -sin(angle), 0, 0}, {sin(angle), cos(angle), 0, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
        mat4 rotZ(rotZarray);
        this->multiply(rotZ);
    }
    float degToRad(float degrees) {
        float radians = degrees*M_PI/180;
        return radians;
    }

    //static functions for generic matrix math
    static mat4 add(mat4 m1, mat4 m2){
        mat4 m = m1;
        m.add(m2);
        return m;
    }
    static mat4 subtract(mat4 m1, mat4 m2){
        mat4 m = m1;
        m.subtract(m2);
        return m;
    }
    static mat4 multiply(mat4 m1, mat4 m2){
        mat4 m = m1;
        m.multiply(m2);
        return m;
    }
};