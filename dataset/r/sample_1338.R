tokenize <- function(text) {
  library(stringr)
  tokens <- str_extract_all(tolower(text), '\\b\\w+\\b')[[1]]
  return(tokens)
}

vectorize <- function(tokens, dictionary) {
  vector <- rep(0, length(dictionary))
  for (token in tokens) {
    if (token %in% names(dictionary)) {
      vector[dictionary[token] + 1] <- vector[dictionary[token] + 1] + 1
    }
  }
  return(vector)
}

main <- function() {
  text <- 'Natural language processing is fascinating'
  dictionary <- c(natural = 1, language = 2, processing = 3, is = 4, fascinating = 5)
  tokens <- tokenize(text)
  vector <- vectorize(tokens, dictionary)
  print(vector)
}

main()