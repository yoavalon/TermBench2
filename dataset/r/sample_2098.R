library(tm)
library(SnowballC)
library(Matrix)
library(caret)

DataProcessor <- setRefClass("DataProcessor",
                             fields = list(documents = "character",
                                           vectorizer = "TermDocumentMatrix"),
                             methods = list(
                               initialize = function(documents) {
                                 .self$documents <- documents
                                 .self$vectorizer <- NULL
                               },
                               fit_transform = function() {
                                 corpus <- Corpus(VectorSource(.self$documents))
                                 corpus <- tm_map(corpus, content_transformer(tolower))
                                 corpus <- tm_map(corpus, removePunctuation)
                                 corpus <- tm_map(corpus, removeNumbers)
                                 corpus <- tm_map(corpus, removeWords, stopwords("en"))
                                 corpus <- tm_map(corpus, stemDocument)
                                 .self$vectorizer <- TermDocumentMatrix(corpus)
                                 return(as.matrix(.self$vectorizer))
                               }
                             ))

ModelEvaluator <- setRefClass("ModelEvaluator",
                              fields = list(vectorized_data = "matrix"),
                              methods = list(
                                initialize = function(vectorized_data) {
                                  .self$vectorized_data <- vectorized_data
                                },
                                evaluate = function() {
                                  norms <- sqrt(rowSums(.self$vectorized_data^2))
                                  return(norms)
                                }
                              ))

ResultAnalyzer <- setRefClass("ResultAnalyzer",
                              fields = list(norms = "numeric"),
                              methods = list(
                                initialize = function(norms) {
                                  .self$norms <- norms
                                },
                                analyze = function() {
                                  mean_norm <- mean(.self$norms)
                                  std_norm <- sd(.self$norms)
                                  max_norm <- max(.self$norms)
                                  min_norm <- min(.self$norms)
                                  return(list(mean = mean_norm, sd = std_norm, max = max_norm, min = min_norm))
                                }
                              ))

main <- function() {
  documents <- c('Python is a great programming language',
                 'Machine learning with Python is fascinating',
                 'Natural language processing is a complex field',
                 'Vectorization is a key concept in NLP',
                 'Understanding floating point precision is crucial')
  processor <- DataProcessor$new(documents)
  vectorized_data <- processor$fit_transform()
  evaluator <- ModelEvaluator$new(vectorized_data)
  norms <- evaluator$evaluate()
  analyzer <- ResultAnalyzer$new(norms)
  result <- analyzer$analyze()
  cat('Mean Norm:', result$mean, '\n')
  cat('Standard Deviation:', result$sd, '\n')
  cat('Max Norm:', result$max, '\n')
  cat('Min Norm:', result$min, '\n')
}

main()