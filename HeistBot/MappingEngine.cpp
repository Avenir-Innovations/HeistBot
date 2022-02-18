#include "MappingEngine.h"

void MappingEngine::GenerateShapes ()
{
    gernatedPolygons.clear();
    bool newShape = true;
    Shape _gen;
    for (int ii = 0; ii < allVertices.size(); ii++)
    {
        bool isUsed = false;
        for (int i = 0; i < polygons.size(); i++)
        {
            if (contains(get(polygons, i).vertices, get(allVertices, ii))) isUsed = true;
            else if (get(polygons, i).IsOnEdge(get(allVertices, ii))) isUsed = true;
        }
        if (!isUsed)
        {
            if (newShape) {_gen = Shape(); _gen.vertices.push_back(get(allVertices, ii)); newShape = false;}
            Vector2 _v;
            bool _b = false;
            for (int i = 0; i < allVertices.size(); i++)
            {
                bool _isUsed = false;
                for (int i = 0; i < polygons.size(); i++)
                {
                    if (contains(get(genernatedPolygons, i).vertices, get(allVertices, ii))) _isUsed = true;
                    else if (get(genernatedPolygons, i).IsOnEdge(get(allVertices, ii))) _isUsed = true;
                }
                if (!_b && i != ii && !_isUsed) {_b = true; _v = get(allVertices, i);} 
                if (!(_isUsed && (_v == get(_gen.vertices, _gen.vertices.size() - 1)) && (_v != get(allVertices, i)) && (distance(get(allVertices, i), get(allVertices, ii)) < distance(_v, get(allVertices, ii))))) _v = get(allVertices, i);
            }
            if (_v != get(_gen.vertices, 0)) _gen.vertices.push_back(_v);
            else {newShape = true;}
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

