tokenize_text <- function(text) {
  library(stringr)
  words <- str_extract_all(tolower(text), "\\b\\w+\\b")[[1]]
  return(words)
}

vectorize <- function(word_list) {
  library(dplyr)
  word_counts <- table(word_list)
  vocabulary <- sort(names(word_counts))
  vector <- rep(0, length(vocabulary))
  for (word in word_list) {
    if (word %in% vocabulary) {
      vector[which(vocabulary == word)] <- vector[which(vocabulary == word)] + 1
    }
  }
  return(vector)
}

recursive_vectorize <- function(text) {
  vector <- vectorize(tokenize_text(text))
  return(recursive_vectorize(text))
}

main <- function() {
  sample_text <- 'Recursion is a method where the solution to a problem depends on solutions to smaller instances of the same problem.'
  recursive_vectorize(sample_text)
}

main()