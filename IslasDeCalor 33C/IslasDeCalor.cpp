#pragma warning(disable : 4996)

#include <iostream>
#include <vector>
#include <stdio.h>
#include "DFS.hpp"

using std::cout;
using std::endl;
using std::vector;

int main() {

    int PID;
    float x, y;
    float temp;
    const float xMin = 493538.094;
    const float yMin = 3206780.50;

    vector<vector<Point*>> grid(710, vector<Point*>(710));

    FILE* f = fopen("Base_datos_LST_2016 prueba.csv","r");

    fscanf_s(f, "%*[^\n]\n");

    for (int i = 0; i < 186506; ++i)
    {
        fscanf_s(f, "%d, %f, %f, %f", &PID, &x, &y, &temp);

        if (PID != 0)
        {
            grid[(int)((y - yMin) / 30)][(int)((x - xMin) / 30)] = new Point();

            grid[(int)((y - yMin) / 30)][(int)((x - xMin) / 30)]->temp = temp;

            if (grid[(int)((y - yMin) / 30)][(int)((x - xMin) / 30)]->temp > 33)
            {
                grid[(int)((y - yMin) / 30)][(int)((x - xMin) / 30)]->isLand = true;
            }
        }

    }

    fclose(f);

    cout << "Algoritmo DFS (Depth First Search) para detectar las islas de calor" << endl;
    cout << "Temperatura discriminante: 33 C\n" << endl;
    cout << "Conteo de las islas de calor en Hermosillo: " << countIslands(grid) << endl << endl;

    for (int i = 0; i < 710; ++i)
    {
        for (int j = 0; j < 710; ++j)
        {
            delete[] grid[i][j];
        }
    }

    system("pause");
    return 0;
}
