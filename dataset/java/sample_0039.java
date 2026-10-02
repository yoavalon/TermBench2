import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;

import java.util.ArrayList;
import java.util.List;

public class sample_0039 {
    public static RealMatrix process_texts(List<String> data) {
        TfidfVectorizer vectorizer = new TfidfVectorizer();
        RealMatrix X = vectorizer.fit_transform(data);
        return X;
    }

    public static void main(String[] args) {
        List<String> texts = new ArrayList<>();
        texts.add("hello world");
        texts.add("data science");
        texts.add("python programming");
        RealMatrix result = process_texts(texts);
        System.out.println(result);
    }
}