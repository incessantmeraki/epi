/* Check whether rectangles intersect, if so return dimensions */

struct Rectangle {
  int x, y, width, height 
}

Rectangle IntersectRectangle(const Rectangle& R1, const Rectangle& R2) {
  if (IsIntersect(R1, R2) {
    return {max(R1.x, R2.x), max(R1.y, R2.y),
            min(R1.x + R1.width, R2.x + R2.width) - max(R1.x, R2.x),
            min(R1.y + R1.height, R2.y + R2.height) - max(R1.y, R2.y)};
  }
  return {0, 0, -1, -1};
}

bool IsIntersect(const Rectangle& R1, const Rectangle& R2) {
  return R1.x <= R2.x + R2.width && R2.x <= R1.x + R1.width &&
         R1.y <= R2.y + R2.height && R2.y <= R1.y + R1.height;
}
