library(Matrix)

preprocess_text <- function(text) {
  text <- tolower(text)
  text <- gsub("[^a-z0-9 ]", "", text)
  return(text)
}

vectorize_text <- function(text) {
  words <- strsplit(text, " ")[[1]]
  unique_words <- unique(words)
  word_index <- setNames(1:length(unique_words), unique_words)
  vector <- rep(0, length(unique_words))
  for (word in words) {
    vector[word_index[word]] <- vector[word_index[word]] + 1
  }
  return(vector)
}

main <- function() {
  input_text <- 'Hello world! This is a test. Hello again.'
  processed_text <- preprocess_text(input_text)
  vector <- vectorize_text(processed_text)
  print(vector)
}

main()