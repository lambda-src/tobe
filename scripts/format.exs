Path.wildcard("../src/**/*.{cpp,hpp}")
|> Enum.reject(fn file ->
  String.contains?(file, "build/") or String.contains?(file, ".git/")
end)
|> Enum.each(fn file -> System.cmd("clang-format", ["-i", file]) end)
