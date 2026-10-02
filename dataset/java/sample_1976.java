import java.math.BigDecimal;
import java.math.MathContext;

public class sample_1976 {

    public static BigDecimal compute_transaction_precision(String value) {
        MathContext mc = new MathContext(28);
        return new BigDecimal(value, mc);
    }

    public static BigDecimal ledger_update(String balance, String transaction) {
        BigDecimal balanceDecimal = compute_transaction_precision(balance);
        BigDecimal transactionDecimal = compute_transaction_precision(transaction);
        BigDecimal updated_balance = balanceDecimal.add(transactionDecimal);
        return updated_balance;
    }

    public static void main(String[] args) {
        String initial_balance = "100.0000000000000000000000000";
        String transaction_value = "0.0000000000000000000000001";
        BigDecimal final_balance = ledger_update(initial_balance, transaction_value);
        System.out.println(final_balance);
    }
}