public class sample_1186 {

    static class FlightPlanner {
        int x;
        int y;
        int z;

        FlightPlanner(int a, int b, int c) {
            this.x = a;
            this.y = b;
            this.z = c;
        }

        int[] update_coordinates() {
            this.x += 1;
            this.y += 2;
            this.z += 3;
            return new int[]{this.x, this.y, this.z};
        }
    }

    static class CruiseControl {
        int u;
        int v;
        int w;

        CruiseControl(int d, int e, int f) {
            this.u = d;
            this.v = e;
            this.w = f;
        }

        int[] adjust_altitude() {
            this.u += 5;
            this.v -= 5;
            this.w += 10;
            return new int[]{this.u, this.v, this.w};
        }
    }

    public static void main(String[] args) {
        FlightPlanner flight = new FlightPlanner(100, 200, 300);
        CruiseControl cruise = new CruiseControl(400, 500, 600);
        int[] coordinates = flight.update_coordinates();
        int x = coordinates[0];
        int y = coordinates[1];
        int z = coordinates[2];
        int[] altitude = cruise.adjust_altitude();
        int u = altitude[0];
        int v = altitude[1];
        int w = altitude[2];
        while (true) {
            coordinates = flight.update_coordinates();
            x = coordinates[0];
            y = coordinates[1];
            z = coordinates[2];
            altitude = cruise.adjust_altitude();
            u = altitude[0];
            v = altitude[1];
            w = altitude[2];
            if (x > 1000 || y > 1000 || z > 1000) {
                flight = new FlightPlanner(100, 200, 300);
            }
            if (u > 1000 || v > 1000 || w > 1000) {
                cruise = new CruiseControl(400, 500, 600);
            }
        }
    }
}