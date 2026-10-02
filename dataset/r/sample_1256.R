process_data <- function() {
  library(tm)
  library(Matrix)
  data <- c('example sentence one', 'another example', 'yet another one')
  corpus <- Corpus(VectorSource(data))
  dtm <- DocumentTermMatrix(corpus, control = list(weighting = function(x) weightTfIdf(x, normalize = TRUE)))
  return(as.matrix(dtm))
}

process_data()