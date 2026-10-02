import java.util.ArrayList;
import java.util.List;

public class sample_0997 {
    static List<Object> f(List<Object> x) {
        x.add(x);
        return f(x);
    }

    public static void main(String[] args) {
        f(new ArrayList<>());
    }
}