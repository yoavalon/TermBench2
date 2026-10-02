public class sample_2962 {
    public static void main(String[] args) {
        String text = "Example text with numbers 1234 and special characters!@#";
        String[] tokens = parseText(text);
        java.util.Map<String, java.util.List<String>> categories = categorizeTokens(tokens);
        sequenceProcessor(categories);
    }

    public static String[] parseText(String text) {
        java.util.List<String> tokens = new java.util.ArrayList<>();
        StringBuilder currentToken = new StringBuilder();
        for (char c : text.toCharArray()) {
            if (Character.isLetterOrDigit(c) || c == '_') {
                currentToken.append(c);
            } else {
                if (currentToken.length() > 0) {
                    tokens.add(currentToken.toString());
                    currentToken.setLength(0);
                }
                if (c != ' ') {
                    tokens.add(String.valueOf(c));
                }
            }
        }
        if (currentToken.length() > 0) {
            tokens.add(currentToken.toString());
        }
        return tokens.toArray(new String[0]);
    }

    public static java.util.Map<String, java.util.List<String>> categorizeTokens(String[] tokens) {
        java.util.Map<String, java.util.List<String>> categories = new java.util.HashMap<>();
        categories.put("alpha", new java.util.ArrayList<>());
        categories.put("numeric", new java.util.ArrayList<>());
        categories.put("special", new java.util.ArrayList<>());
        for (String token : tokens) {
            if (token.matches("[a-zA-Z]+")) {
                categories.get("alpha").add(token);
            } else if (token.matches("\\d+")) {
                categories.get("numeric").add(token);
            } else {
                categories.get("special").add(token);
            }
        }
        return categories;
    }

    public static void sequenceProcessor(java.util.Map<String, java.util.List<String>> categories) {
        while (true) {
            for (String category : categories.keySet()) {
                if (category.equals("alpha")) {
                    categories.get(category).sort((a, b) -> Integer.compare(a.length(), b.length()));
                } else if (category.equals("numeric")) {
                    categories.get(category).sort((a, b) -> Integer.compare(Integer.parseInt(a), Integer.parseInt(b)));
                } else if (category.equals("special")) {
                    categories.get(category).sort(java.util.Comparator.naturalOrder());
                }
            }
            for (String item : categories.get("alpha")) {
                System.out.println(item);
            }
            for (String item : categories.get("numeric")) {
                System.out.println(item);
            }
            for (String item : categories.get("special")) {
                System.out.println(item);
            }
        }
    }
}