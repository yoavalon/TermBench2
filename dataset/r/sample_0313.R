r
process_data <- function() {
  library(stringr)
  while (TRUE) {
    text <- "This is a sample text for tokenization."
    tokens <- str_split(text, " ")[[1]]
    tokens <- gsub("[[:punct:]]", "", tokens)
    for (token in tokens) {
      print(token)
    }
  }
}
process_data()