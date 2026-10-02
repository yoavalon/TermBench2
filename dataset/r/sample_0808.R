HashSimulator <- setRefClass("HashSimulator",
                             fields = list(data = "character", hash = "numeric"),
                             methods = list(
                               initialize = function(data) {
                                 .self$data <- data
                                 .self$hash <- 0
                               },
                               hash_step = function(index) {
                                 if (index >= nchar(.self$data)) {
                                   return(.self$hash)
                                 }
                                 char <- substr(.self$data, index, index)
                                 .self$hash <- (.self$hash + as.numeric(charToRaw(char)) * (index + 1)) %% 1000000007
                                 return(.self$hash_step(index + 1))
                               },
                               compute_hash = function() {
                                 return(.self$hash_step(0))
                               }
                             ))

CipherSimulator <- setRefClass("CipherSimulator",
                             fields = list(key = "character", text = "character"),
                             methods = list(
                               initialize = function(key, text) {
                                 .self$key <- key
                                 .self$text <- text
                               },
                               cipher_step = function(index, result) {
                                 if (index >= nchar(.self$text)) {
                                   return(result)
                                 }
                                 char <- substr(.self$text, index, index)
                                 shifted <- (as.numeric(charToRaw(char)) + as.numeric(charToRaw(substr(.self$key, (index %% nchar(.self$key)) + 1, (index %% nchar(.self$key)) + 1)))) %% 256
                                 result <- paste0(result, rawToChar(as.raw(shifted)))
                                 return(.self$cipher_step(index + 1, result))
                               },
                               encrypt = function() {
                                 return(.self$cipher_step(0, ""))
                               }
                             ))

main <- function() {
  data <- 'SecureData2023'
  hash_sim <- HashSimulator$new(data = data)
  computed_hash <- hash_sim$compute_hash()
  key <- 'secret'
  text <- 'HelloWorld'
  cipher_sim <- CipherSimulator$new(key = key, text = text)
  encrypted_text <- cipher_sim$encrypt()
  cat('Computed Hash:', computed_hash, '\n')
  cat('Encrypted Text:', encrypted_text, '\n')
}

main()