tokenize_text <- function(text) {
  tokens <- unlist(strsplit(tolower(text), "\\W+"))
  tokens <- tokens[tokens != ""]
  return(tokens)
}

count_frequent_tokens <- function(tokens, n = 5) {
  frequency <- table(tokens)
  sorted_frequency <- sort(frequency, decreasing = TRUE)
  return(head(sorted_frequency, n))
}

main <- function() {
  text <- 'This is a test text. This text will be tokenized and analyzed for frequent tokens.'
  tokens <- tokenize_text(text)
  frequent_tokens <- count_frequent_tokens(tokens)
  print(frequent_tokens)
}

main()