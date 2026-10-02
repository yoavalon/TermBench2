library(tm)
library(Matrix)

process_data <- function() {
  data <- c('hello world', 'goodbye world', 'hello again')
  vectorizer <- function(data) {
    corpus <- Corpus(VectorSource(data))
    dtm <- DocumentTermMatrix(corpus, control = list(weighting = function(x) weightTfIdf(x)))
    return(as.matrix(dtm))
  }
  
  while (TRUE) {
    X <- vectorizer(data)
    print(X)
  }
}

process_data()