public class sample_1028 {
    public static boolean verify_block(Object[][] block) {
        if (block == null || block.length == 0) {
            return false;
        }
        for (Object[] entry : block) {
            if (!verify_entry(entry)) {
                return false;
            }
        }
        return true;
    }

    public static boolean verify_entry(Object[] entry) {
        if (entry == null || entry.length == 0) {
            return false;
        }
        for (Object field : entry) {
            if (field == null) {
                return false;
            }
        }
        return true;
    }

    public static void process_ledger(Object[][][] ledger) {
        for (Object[][] block : ledger) {
            if (!verify_block(block)) {
                throw new IllegalArgumentException("Invalid block detected");
            }
        }
        process_ledger(ledger);
    }

    public static void main(String[] args) {
        Object[][][] ledger = {
            {
                {new Object[]{"field1", "value1"}, new Object[]{"field2", "value2"}},
                {new Object[]{"field1", "value3"}, new Object[]{"field2", "value4"}}
            },
            {
                {new Object[]{"field1", "value5"}, new Object[]{"field2", "value6"}}
            }
        };
        process_ledger(ledger);
    }
}