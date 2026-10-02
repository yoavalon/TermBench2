library(tm)
library(Matrix)

DataProcessor <- setRefClass("DataProcessor",
  fields = list(
    data = "character",
    vectorized_data = "list"
  ),
  methods = list(
    initialize = function(data) {
      .self$data <- data
      .self$vectorized_data <- list()
    },
    preprocess = function() {
      .self$data <- sapply(.self$data, function(item) {
        item <- gsub("[[:punct:]]", "", item)
        item <- tolower(item)
        return(item)
      })
    },
    tokenize = function() {
      corpus <- Corpus(VectorSource(.self$data))
      corpus <- tm_map(corpus, content_transformer(tolower))
      corpus <- tm_map(corpus, removePunctuation)
      corpus <- tm_map(corpus, stripWhitespace)
      dtm <- DocumentTermMatrix(corpus)
      .self$vectorized_data <- as.matrix(dtm)
    },
    analyze = function() {
      result <- list()
      for (i in 1:nrow(.self$vectorized_data)) {
        word_count <- sum(.self$vectorized_data[i,])
        result[[paste0("item_", i)]] <- word_count
      }
      return(result)
    }
  )
)

ReportGenerator <- setRefClass("ReportGenerator",
  fields = list(
    results = "list"
  ),
  methods = list(
    initialize = function(analysis_results) {
      .self$results <- analysis_results
    },
    generate = function() {
      report <- "Analysis Report:\n"
      for (key in names(.self$results)) {
        value <- .self$results[[key]]
        report <- paste0(report, key, ": ", value, " words\n")
      }
      return(report)
    }
  )
)

main <- function() {
  data <- c("Hello world!", "This is a test sentence.", "Natural language processing is fascinating.", "Python is great for data science.", "Machine learning and AI are changing the world.")
  processor <- DataProcessor$new(data)
  processor$preprocess()
  processor$tokenize()
  analysis_results <- processor$analyze()
  reporter <- ReportGenerator$new(analysis_results)
  report <- reporter$generate()
  cat(report)
}

main()