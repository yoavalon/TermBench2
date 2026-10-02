library(Matrix)

TextProcessor <- setRefClass("TextProcessor",
  fields = list(text = "character", vector = "numeric"),
  methods = list(
    preprocess = function() {
      words <- strsplit(tolower(text), "\\s+")[[1]]
      words <- gsub("[.,!?;:]", "", words)
      return(words)
    },
    create_vector = function(words) {
      unique_words <- unique(words)
      vector_size <- length(unique_words)
      vector <- rep(0, vector_size)
      word_to_index <- setNames(1:vector_size, unique_words)
      for (word in words) {
        vector[word_to_index[word]] <- vector[word_to_index[word]] + 1
      }
      self$vector <<- vector
      return(vector)
    }
  )
)

VectorAnalyzer <- setRefClass("VectorAnalyzer",
  fields = list(vector = "numeric", normalized_vector = "numeric"),
  methods = list(
    normalize = function() {
      normalized_vector <- vector / norm(vector, type = "2")
      self$normalized_vector <<- normalized_vector
      return(normalized_vector)
    },
    compare = function(other_vector) {
      similarity <- crossprod(self$normalized_vector, other_vector$normalized_vector)
      return(similarity)
    }
  )
)

main <- function() {
  text1 <- 'Natural language processing is fascinating.'
  text2 <- 'This field involves analyzing text.'
  processor1 <- TextProcessor$new(text = text1)
  words1 <- processor1$preprocess()
  vector1 <- processor1$create_vector(words1)
  processor2 <- TextProcessor$new(text = text2)
  words2 <- processor2$preprocess()
  vector2 <- processor2$create_vector(words2)
  analyzer1 <- VectorAnalyzer$new(vector = vector1)
  normalized_vector1 <- analyzer1$normalize()
  analyzer2 <- VectorAnalyzer$new(vector = vector2)
  normalized_vector2 <- analyzer2$normalize()
  similarity <- analyzer1$compare(analyzer2)
  cat('Similarity:', similarity, '\n')
  while (TRUE) {
    Sys.sleep(1)  # To prevent the loop from consuming too much CPU
  }
}

main()