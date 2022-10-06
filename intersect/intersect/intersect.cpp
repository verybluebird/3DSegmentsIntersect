#include <iostream>
#include "vectors3D.h"
#include "intersect.h"


void printResult(Segment3D &s1, Segment3D &s2) {
    
    std::cout << "Segment 1:\n" << s1;
    std::cout << "Segment 2:\n" << s2;
    Vector3D point;
    bool res = s1.Intersect(s2, point);
    if (res == true)
        std::cout << "Point of intersection is: " << point << "\n\n";
    
}

int main()
{
    //---------------------------1
    Vector3D start = { 1, 1, 0 };
    Vector3D end = { 1, 3, 0 };
    Segment3D s1 = { start, end };

    start = { 3, 1, 0 };
    end = { 3, 3, 0 };
    Segment3D s2 = { start, end };
    printResult(s1, s2); 
    //---------------------------2
    start = { 1, 1, 0 };
    end = { 1, 3, 0 };
    s1 = { start, end };

    start = { 1, 4, 0 };
    end = { 1, 1, 0 };
    s2 = { start, end };
    printResult(s1, s2);
    //---------------------------3
    start = { 1, 1, 0 };
    end = { 3, 3, 0 };
    s1 = { start, end };

    start = { 3, 1, 0 };
    end = { 1, 3, 0 };
    s2 = { start, end };
    printResult(s1, s2);
    //---------------------------4
    start = { 1, 0, 0 };
    end = { 0, 1, 1 };
    s1 = { start, end };

    start = { 0, 0, 0 };
    end = { 1, 1, 1 };
    s2 = { start, end };
    printResult(s1, s2);

    //---------------------------5

    start = { 0, 0, 0 };
    end = { 0, 1, 1 };
    s1 = { start, end };

    start = { 1, 0, 0 };
    end = { 1, 0, 1 };
    s2 = { start, end };
    printResult(s1, s2);
    //---------------------------6

    start = { 0, 0, 0 };
    end = { 0, 1, 1 };
    s1 = { start, end };

    start = { 1, 0, 0 };
    end = { 1, 1, 1 };
    s2 = { start, end };
    printResult(s1, s2);
    //---------------------------7
    start = { 0, 0, 0 };
    end = { 1, 1, 0 };
    s1 = { start, end };

    start = { 3, 1, 0 };
    end = { 1, 3, 0 };
    s2 = { start, end };
    printResult(s1, s2);
    //---------------------------8
    start = { 0, 0, 0 };
    end = { 1, 0, 1 };
    s1 = { start, end };

    start = { 0, 0, 1 };
    end = { 1, 0, 1 }; 
    s2 = { start, end };
    printResult(s1, s2);
    //---------------------------10

    start = { 1, 1, 0 };
    end = { 1, 3, 0 };
    s1 = { start, end };

    start = { 1, 4, 0 };
    end = { 1, 5, 0 };
    s2 = { start, end };
    printResult(s1, s2);
    //---------------------------11
    start = { 1, 1, 0 };
    end = { 1, 3, 0 };
    s1 = { start, end };

    start = { 1, 0, 0 };
    end = { 1, 5, 0 };
    s2 = { start, end };
    printResult(s1, s2);
    //---------------------------12
    start = { 1, 1, 0 };
    end = { 1, 3, 0 };
    s1 = { start, end };

    start = { 1, 3, 0 };
    end = { 1, 5, 0 };
    s2 = { start, end };
    printResult(s1, s2);
}

