{pkgs, ...}: {
  packages = [pkgs.clang-tools pkgs.llvm];

  languages.elixir.enable = true;
  languages.cplusplus.enable = true;
}
