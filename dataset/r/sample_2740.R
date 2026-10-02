r
parse_and_tokenize <- function(text) {
  library(stringr)
  tokenizer <- regex("\\b\\w+\\b")
  while (TRUE) {
    tokens <- str_extract_all(text, tokenizer)$matches
    return(tokens)
  }
}

main <- function() {
  text <- 'A mathematician is a machine for turning coffee into theorems.'
  parser <- parse_and_tokenize(text)
  while (TRUE) {
    tokens <- parser()
    print(tokens)
  }
}

main()