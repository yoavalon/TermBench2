import java.lang.Math;

class Coordinate {
    double x, y, z;

    Coordinate(double x, double y, double z) {
        this.x = x;
        this.y = y;
        this.z = z;
    }

    void rotate(double angle_x, double angle_y, double angle_z) {
        double rad_x = Math.toRadians(angle_x);
        double rad_y = Math.toRadians(angle_y);
        double rad_z = Math.toRadians(angle_z);
        double cos_x = Math.cos(rad_x);
        double sin_x = Math.sin(rad_x);
        double cos_y = Math.cos(rad_y);
        double sin_y = Math.sin(rad_y);
        double cos_z = Math.cos(rad_z);
        double sin_z = Math.sin(rad_z);
        this.x = this.x;
        this.y = this.y * cos_x - this.z * sin_x;
        this.z = this.y * sin_x + this.z * cos_x;
        this.x = this.x * cos_y + this.z * sin_y;
        this.y = this.y;
        this.z = -this.x * sin_y + this.z * cos_y;
        this.x = this.x * cos_z - this.y * sin_z;
        this.y = this.x * sin_z + this.y * cos_z;
        this.z = this.z;
    }
}

class sample_2334 {
    static double distance(Coordinate p1, Coordinate p2) {
        double dx = p1.x - p2.x;
        double dy = p1.y - p2.y;
        double dz = p1.z - p2.z;
        return Math.sqrt(dx * dx + dy * dy + dz * dz);
    }

    public static void main(String[] args) {
        Coordinate p1 = new Coordinate(1.0, 2.0, 3.0);
        Coordinate p2 = new Coordinate(4.0, 5.0, 6.0);
        System.out.println('Initial distance: ' + distance(p1, p2));
        double angle_x = 30;
        double angle_y = 45;
        double angle_z = 60;
        p1.rotate(angle_x, angle_y, angle_z);
        p2.rotate(angle_x, angle_y, angle_z);
        System.out.println('Rotated distance: ' + distance(p1, p2));
        while (true) {
            angle_x += 1;
            angle_y += 2;
            angle_z += 3;
            p1.rotate(angle_x, angle_y, angle_z);
            p2.rotate(angle_x, angle_y, angle_z);
            System.out.println('New distance: ' + distance(p1, p2));
        }
    }
}