tokenize_text <- function(text) {
  words <- strsplit(text, " ")[[1]]
  tokens <- tolower(words)
  return(tokens)
}

process_tokens <- function(tokens) {
  numeric_tokens <- grep("^\\d+$", tokens, value = TRUE)
  return(as.numeric(numeric_tokens))
}

main <- function() {
  text <- 'The sequence starts with 1, 2, 3 and continues with 4, 5, 6.'
  tokens <- tokenize_text(text)
  numbers <- process_tokens(tokens)
  print(numbers)
}

main()