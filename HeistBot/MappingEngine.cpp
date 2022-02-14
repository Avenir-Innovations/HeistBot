#include "MappingEngine.h"

void MappingEngine::GenerateShape (Vector2 _input)
{
    Shape polygon = get(polygons, 0);
    for (int i = 0; i < polygons.size(); i++)
    {
        polygon = get(polygons, i);
        for (int i = 0; i < (polygon).vertices.size(); i++)
        {
            
        }
    }
}

void MappingEngine::CheckShapes ()
{
    int inputSize = inputPoints.size();
    int polygonSize = polygons.size();
    list<Vector2> _ip = inputPoints;
    Vector2 vertex = get(inputPoints, 0);
    for (int ii = 0; ii < inputSize; ii++)
    {
        vertex = get(inputPoints, ii);
        bool addVertex = true;
        Shape polygon = get(polygons, 0);
        for (int i = 0; i < polygonSize; i++)
        {
            polygon = get(polygons, i);
            if (polygon.IsInside(vertex))
            {
                addVertex = false;
            }
            else
            {
                
            }
            if (addVertex) allVertices.push_back(vertex);
            _ip.remove(vertex);
        }
        
    }
}

void MappingEngine::Update ()
{
    while (true)
    {
        //std::thread thread1(&MappingEngine::CheckShapes, this);
        
        
        //thread1.join();
    }
}

void MappingEngine::Initialize ()
{
    Update();
}

