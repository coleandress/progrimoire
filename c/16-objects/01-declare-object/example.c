#include <stdio.h>

struct Point2D
{
   int mX;
   int mY;
};

typedef struct
{
   int mX;
   int mY;
   int mZ;

} Point3D;

static struct Point2D makePoint2D(int x, int y)
{
   struct Point2D theObject = { 0 };

   theObject.mX = x;
   theObject.mY = y;

   return(theObject);
}

static void printPoint2D(struct Point2D p)
{
   printf("{ x: %d, y: %d }\n", p.mX, p.mY);
}

static Point3D makePoint3D(int x, int y, int z)
{
   Point3D theObject = { 0 };

   theObject.mX = x;
   theObject.mY = y;
   theObject.mZ = z;

   return(theObject);
}

static void printPoint3D(Point3D p)
{
   printf("{ x: %d, y: %d, z: %d }\n", p.mX, p.mY, p.mZ);
}

int main()
{
   struct Point2D p1 = makePoint2D(2, 3);
   printPoint2D(p1);

   Point3D p2 = makePoint3D(2, 3, 4);
   printPoint3D(p2);

   return(0);
}
