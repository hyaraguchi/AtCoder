
/*
 * A = (ax, ay), B = (bx, by), C = (Cx, cy), D = (dx, dy) とする時、
 * 線分ABと線分CDが交差するかどうかを判定する. (交差するならtrue, しないならfalseを返す)
*/ 

bool jugdeIntersected(double ax, double ay, double bx, double by, 
                        double cx, double cy, double dx, double dy) {
    double ta = (cx - dx) * (ay - cy) + (cy - dy) * (cx - ax);
    double tb = (cx - dx) * (by - cy) + (cy - dy) * (cx - bx);
    double tc = (ax - bx) * (cy - ay) + (ay - by) * (ax - cx);
    double td = (ax - bx) * (dy - ay) + (ay - by) * (ax - dx);

    return tc * td < 0 && ta * tb < 0;
}