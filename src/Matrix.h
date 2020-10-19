#pragma once

#include <vector>


typedef float Matrix4x4[4][4];
static class Matrix_Cal
{
public:
	static void Multiple(Matrix4x4 A, float* B, int size = 4)
	{
        float* ret = new float[size];
        for (int i = 0; i < size; i++)
        {
            ret[i] = 0;
            for (int j = 0; j < size; j++)
            {
                ret[i] += (A[i][j] * B[j]);
            }
        }
        for (int i = 0; i < size; i++)
            B[i] = ret[i];
        delete[] ret;
	}

    static void Multiple4x4(Matrix4x4 A, Matrix4x4 B)
    {
        float** ret = new float* [4];
        for (int i = 0; i < 4; i++)
            ret[i] = new float[4];

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                ret[i][j] = 0;
                for (int k = 0; k < 4; k++)
                    ret[i][j] += A[i][k] * B[k][j];
            }
        }
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
                A[i][j] = ret[i][j];
        }
        for (int i = 0; i < 4; i++)
        {
            delete[] ret[i];
        }
        delete[] ret;
    }

    void Transpose(Matrix4x4 matrix)
    {
        float** reg = new float*[4];
        for (int i = 0; i < 4; i++)
        {
            reg[i] = new float[4];
            for (int j = 0; j < 4; j++)
                reg[i][j] = matrix[i][j];
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                matrix[i][j] = reg[j][i];
            }
        }


        for (int i = 0; i < 4; i++)
            delete[] reg[i];
        delete[] reg;
    }
};