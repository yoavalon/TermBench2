tokenize <- function(sentence, index = 1, tokens = character(0)) {
  if (index > nchar(sentence) || substr(sentence, index, index) == " ") {
    return(tokens)
  }
  if (index == 1 || substr(sentence, index - 1, index - 1) == " ") {
    start <- index
  }
  while (index <= nchar(sentence) && substr(sentence, index, index) != " ") {
    index <- index + 1
  }
  tokens <- c(tokens, substr(sentence, start, index - 1))
  return(tokenize(sentence, index, tokens))
}

main <- function() {
  sentence <- 'example sentence for tokenization'
  result <- tokenize(sentence)
  print(result)
}

main()