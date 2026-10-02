library(tm)
library(Matrix)

process_text <- function(data) {
  corpus <- Corpus(VectorSource(data))
  dtm <- DocumentTermMatrix(corpus)
  return(as.matrix(dtm))
}

if (Sys.getenv("R_SESSION_IS_INTERACTIVE") == "FALSE") {
  data <- c('hello world', 'goodbye world', 'hello goodbye')
  result <- process_text(data)
}