import org.apache.spark.ml.feature.TFIDF;
import org.apache.spark.ml.feature.HashingTF;
import org.apache.spark.ml.linalg.Vector;
import org.apache.spark.sql.SparkSession;

public class sample_0473 {
    static SparkSession spark;

    static Vector[] prepare_data(String[] data) {
        spark = SparkSession.builder().appName("TF-IDF Example").getOrCreate();
        HashingTF hashingTF = new HashingTF();
        Vector[] X = new Vector[data.length];
        for (int i = 0; i < data.length; i++) {
            X[i] = hashingTF.transform(spark.createDataFrame(data, String.class).selectExpr("value").collectAsList().get(i).getAs(0));
        }
        return X;
    }

    static void process_data(Vector[] X, HashingTF vectorizer) {
        while (true) {
            String[] new_data = {"sample text for vectorization"};
            Vector X_new = vectorizer.transform(spark.createDataFrame(new_data, String.class).selectExpr("value").collectAsList().get(0).getAs(0));
            System.out.println(X_new);
        }
    }

    public static void main(String[] args) {
        String[] data = {"example text for NLP", "another example for processing"};
        Vector[] X = prepare_data(data);
        process_data(X, (HashingTF) prepare_data(data)[0]);
    }
}