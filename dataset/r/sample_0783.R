tokenize <- function(text) {
  if (nchar(text) == 0) {
    return(character(0))
  } else {
    split_text <- strsplit(text, " ", fixed = TRUE)[[1]]
    word <- split_text[1]
    rest <- paste(split_text[-1], collapse = " ")
    return(c(word, tokenize(rest)))
  }
}

vectorize <- function(tokens, index = 1, vector = list()) {
  if (index > length(tokens)) {
    return(vector)
  } else {
    token <- tokens[index]
    if (!(token %in% names(vector))) {
      vector[[token]] <- 0
    }
    vector[[token]] <- vector[[token]] + 1
    return(vectorize(tokens, index + 1, vector))
  }
}

main <- function() {
  text <- 'hello world hello'
  tokens <- tokenize(text)
  vector <- vectorize(tokens)
  print(vector)
}

main()