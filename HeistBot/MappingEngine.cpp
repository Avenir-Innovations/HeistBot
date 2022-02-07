#include "MappingEngine.h"

void MappingEngine::GenerateShape (Vector2 _input)
{
    list<Shape>::iterator polygon = polygons.begin();
    for (int i = 0; i < size(polygons); i++)
    {
        for (int i = 0; i < (*polygon).vertices.size(); i++)
        {
            
        }
    }
}

void MappingEngine::CheckShapes ()
{
    int inputSize = size(inputPoints);
    list<Vector2> _ip = inputPoints;
    list<Vector2>::iterator vertex = inputPoints.begin();
    for (int ii = 0; ii < inputSize; ii++)
    {
        list<Shape>::iterator polygon = polygons.begin();
        for (int i = 0; i < size(polygons); i++)
        {
            if ((find(((*polygon).vertices).begin(), ((*polygon).vertices).end(), ((*polygon).vertices)) != ((*polygon).vertices).end()) || (*polygon).IsInside(*vertex))
            {
                _ip.remove(*vertex);
            }
            else
            {
                GenerateShape(*vertex);
                _ip.remove(*vertex);
            }
            if (i < size(polygons) - 1) polygon = next(polygon, 1);
        }
        if (ii < inputSize - 1) vertex = next(vertex, 1);
    }
}

void MappingEngine::Update ()
{
    while (true)
    {
        std::thread thread1(CheckShapes);
        
        
        thread1.join();
    }
}

void MappingEngine::Initialize ()
{
    Update();
}

