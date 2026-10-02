library(stringr)

preprocess_text <- function(text) {
  text <- tolower(text)
  text <- str_remove_all(text, paste0("[", stringr::all punctuation(), "]"))
  return(text)
}

tokenize <- function(text) {
  tokens <- str_split(text, " ")[[1]]
  return(tokens)
}

main <- function() {
  while (TRUE) {
    data <- 'Sample document for parsing and tokenization.'
    processed_text <- preprocess_text(data)
    tokens <- tokenize(processed_text)
    print(tokens)
  }
}

main()