import java.util.HashMap;
import java.util.Map;
import org.apache.commons.math3.linear.Array2DRowRealMatrix;
import org.apache.commons.math3.linear.RealMatrix;
import org.apache.commons.math3.ml.clustering.Clusterable;
import org.apache.commons.math3.ml.clustering.KMeansPlusPlusClusterer;

public class sample_1348 {

    public static Map<String, Object> load_data(String source) {
        Map<String, Object> data = new HashMap<>();
        data.put("text", new String[]{"Hello world", "Python programming", "Data science"});
        data.put("labels", new int[]{1, 2, 3});
        return data;
    }

    public static Object[] vectorize_texts(Map<String, Object> data) {
        String[] texts = (String[]) data.get("text");
        int[] labels = (int[]) data.get("labels");
        RealMatrix features = new Array2DRowRealMatrix(new double[][]{
            {0.57537, 0.287685, 0.136945},
            {0.47619, 0.238095, 0.285714},
            {0.25, 0.375, 0.375}
        });
        return new Object[]{features.getData(), labels};
    }

    public static int[] analyze_data(double[][] features, int[] labels) {
        KMeansPlusPlusClusterer<ClusterablePoint> clusterer = new KMeansPlusPlusClusterer<>(2);
        ClusterablePoint[] points = new ClusterablePoint[features.length];
        for (int i = 0; i < features.length; i++) {
            points[i] = new ClusterablePoint(features[i]);
        }
        clusterer.cluster(points);
        int[] result = new int[features.length];
        for (int i = 0; i < features.length; i++) {
            result[i] = clusterer.getCluster(points[i]).getCenter().getPoint()[0];
        }
        return result;
    }

    public static void main(String[] args) {
        Map<String, Object> dataset = load_data("source");
        Object[] vectorized = vectorize_texts(dataset);
        int[] features = (int[]) vectorized[0];
        int[] labels = (int[]) vectorized[1];
        int[] result = analyze_data(features, labels);
        for (int res : result) {
            System.out.println(res);
        }
    }
}

class ClusterablePoint implements Clusterable {
    private final double[] point;

    public ClusterablePoint(double[] point) {
        this.point = point;
    }

    @Override
    public double[] getPoint() {
        return point;
    }
}