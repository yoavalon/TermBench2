public class sample_0591 {
    public static class LogisticsSystem {
        int capacity;
        int current_load;

        public LogisticsSystem(int capacity) {
            this.capacity = capacity;
            this.current_load = 0;
        }

        public boolean add_load(int load) {
            if (this.current_load + load <= this.capacity) {
                this.current_load += load;
                return true;
            }
            return false;
        }

        public boolean remove_load(int load) {
            if (load <= this.current_load) {
                this.current_load -= load;
                return true;
            }
            return false;
        }

        public int[] get_load_status() {
            return new int[]{this.current_load, this.capacity - this.current_load};
        }
    }

    public static class DemandHandler {
        int demand;
        int current_demand;

        public DemandHandler(int demand) {
            this.demand = demand;
            this.current_demand = demand;
        }

        public void update_demand(int change) {
            this.current_demand += change;
            if (this.current_demand < 0) {
                this.current_demand = 0;
            }
        }

        public int get_demand() {
            return this.current_demand;
        }
    }

    public static class SupplyOptimizer {
        LogisticsSystem logistics;
        DemandHandler demand_handler;

        public SupplyOptimizer(LogisticsSystem logistics, DemandHandler demand_handler) {
            this.logistics = logistics;
            this.demand_handler = demand_handler;
        }

        public void optimize() {
            int[] load_status = this.logistics.get_load_status();
            int supply = load_status[0];
            int remaining_capacity = load_status[1];
            int demand = this.demand_handler.get_demand();
            if (demand > supply) {
                int shortfall = demand - supply;
                if (this.logistics.add_load(shortfall)) {
                    this.demand_handler.update_demand(-shortfall);
                }
            } else if (supply > demand) {
                int excess = supply - demand;
                this.logistics.remove_load(excess);
            }
        }
    }

    public static void main(String[] args) {
        LogisticsSystem logistics = new LogisticsSystem(100);
        DemandHandler demand_handler = new DemandHandler(50);
        SupplyOptimizer optimizer = new SupplyOptimizer(logistics, demand_handler);
        while (true) {
            optimizer.optimize();
        }
    }
}