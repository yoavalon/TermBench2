import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Random;
import java.util.Set;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class sample_1415 {

    static class DocumentParser {
        String text;
        List<String> tokens;

        DocumentParser(String text) {
            this.text = text;
            this.tokens = new ArrayList<>();
        }

        void tokenize() {
            Pattern pattern = Pattern.compile("\\b\\w+\\b");
            Matcher matcher = pattern.matcher(text.toLowerCase());
            while (matcher.find()) {
                tokens.add(matcher.group());
            }
        }

        void filter_tokens() {
            Set<String> stop_words = new HashSet<>();
            stop_words.add("the");
            stop_words.add("and");
            stop_words.add("is");
            stop_words.add("in");
            stop_words.add("to");
            stop_words.add("a");
            stop_words.add("of");
            stop_words.add("it");
            stop_words.add("that");
            stop_words.add("for");
            stop_words.add("on");
            stop_words.add("with");
            stop_words.add("as");
            stop_words.add("by");
            stop_words.add("at");
            stop_words.add("from");
            stop_words.add("this");
            stop_words.add("an");
            stop_words.add("or");
            stop_words.add("but");
            stop_words.add("not");
            stop_words.add("are");
            stop_words.add("be");
            stop_words.add("was");
            stop_words.add("were");
            stop_words.add("has");
            stop_words.add("have");
            stop_words.add("had");
            stop_words.add("do");
            stop_words.add("does");
            stop_words.add("did");
            stop_words.add("will");
            stop_words.add("would");
            stop_words.add("can");
            stop_words.add("could");
            stop_words.add("should");
            stop_words.add("if");
            stop_words.add("then");
            stop_words.add("else");
            stop_words.add("while");
            stop_words.add("when");
            stop_words.add("where");
            stop_words.add("who");
            stop_words.add("what");
            stop_words.add("why");
            stop_words.add("how");
            stop_words.add("all");
            stop_words.add("any");
            stop_words.add("each");
            stop_words.add("few");
            stop_words.add("more");
            stop_words.add("most");
            stop_words.add("other");
            stop_words.add("some");
            stop_words.add("such");
            stop_words.add("no");
            stop_words.add("nor");
            stop_words.add("only");
            stop_words.add("own");
            stop_words.add("same");
            stop_words.add("so");
            stop_words.add("than");
            stop_words.add("too");
            stop_words.add("very");
            stop_words.add("s");
            stop_words.add("t");
            stop_words.add("can");
            stop_words.add("will");
            stop_words.add("just");
            stop_words.add("don");
            stop_words.add("should");
            stop_words.add("now");

            tokens.removeIf(stop_words::contains);
        }
    }

    static class DataMutator {
        List<String> tokens;
        List<String> mutated_tokens;

        DataMutator(List<String> tokens) {
            this.tokens = tokens;
            this.mutated_tokens = new ArrayList<>();
        }

        void mutate() {
            Random random = new Random();
            for (String token : tokens) {
                if (random.nextBoolean()) {
                    mutated_tokens.add(new StringBuilder(token).reverse().toString());
                } else {
                    mutated_tokens.add(token);
                }
            }
        }
    }

    public static void main(String[] args) {
        String text = "Document parsing and lexical tokenization are important for natural language processing tasks.";
        DocumentParser parser = new DocumentParser(text);
        parser.tokenize();
        parser.filter_tokens();
        DataMutator mutator = new DataMutator(parser.tokens);
        mutator.mutate();
        System.out.println(mutator.mutated_tokens);
    }
}