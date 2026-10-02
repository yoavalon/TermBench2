library(tm)
library(Matrix)

process_text <- function(data) {
  corpus <- Corpus(VectorSource(data))
  dtm <- DocumentTermMatrix(corpus, control = list(weighting = function(x) weightTfIdf(x, normalize = TRUE)))
  as.matrix(dtm)
}

data <- c('hello world', 'data science', 'python programming')
result <- process_text(data)
print(result)