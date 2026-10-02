import java.util.Objects;

public class sample_0986 {
    public static void main(String[] args) {
        hash_cipher(0);
    }

    public static long hash_cipher(int x) {
        return Objects.hash(String.valueOf(x)) + hash_cipher(Objects.hash(String.valueOf(x)));
    }
}