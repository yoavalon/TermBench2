library(tm)
library(Matrix)

preprocess_texts <- function(data) {
  corpus <- Corpus(VectorSource(data))
  dtm <- DocumentTermMatrix(corpus, control = list(weighting = function(x) weightTfIdf(x, normalize = TRUE), 
                                                        max.features = 100))
  return(as.matrix(dtm))
}

analyze_data <- function(matrix) {
  result <- rowSums(matrix)
  return(result)
}

main <- function() {
  texts <- c('hello world', 'goodbye world', 'hello universe')
  matrix <- preprocess_texts(texts)
  result <- analyze_data(matrix)
  print(result)
}

main()