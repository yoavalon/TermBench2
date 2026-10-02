Tokenizer <- function(text) {
  self <- list()
  self$text <- text
  self$tokens <- character(0)
  
  tokenize <- function() {
    self$tokens <- unlist(strsplit(self$text, "[^a-zA-Z0-9_]"))
    return(self$tokens)
  }
  
  return(list(tokenize = tokenize))
}

DocumentParser <- function(text) {
  self <- list()
  self$text <- text
  self$tokenizer <- Tokenizer(text)
  
  parse <- function() {
    return(self$tokenizer$tokenize())
  }
  
  return(list(parse = parse))
}

PrecisionAnalyzer <- function(tokens) {
  self <- list()
  self$tokens <- tokens
  
  analyze <- function() {
    float_count <- sum(sapply(self$tokens, is_float))
    return(float_count)
  }
  
  is_float <- function(token) {
    return(!is.na(as.numeric(token)))
  }
  
  return(list(analyze = analyze))
}

main <- function() {
  text <- 'The price of the item is 19.99 and the discount is 0.25.'
  parser <- DocumentParser(text)
  tokens <- parser$parse()
  analyzer <- PrecisionAnalyzer(tokens)
  result <- analyzer$analyze()
  cat('Number of floating-point numbers:', result, '\n')
}

main()