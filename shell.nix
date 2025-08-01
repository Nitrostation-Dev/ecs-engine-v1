{ pkgs ? import <nixpkgs> {} }:
pkgs.mkShell {
	nativeBuildInputs = with pkgs; [
		bear
		cmake
		gnumake
	];

	buildInputs = with pkgs; [
		cmake
		pkg-config
		gcc
		
		# GLFW dependencies
		xorg.libX11
		xorg.libXcursor
		xorg.libXi
		xorg.libXinerama
		xorg.libXrandr
		xorg.libXxf86vm
		
		# Wayland support
		wayland
		wayland-scanner
		wayland-protocols
		libxkbcommon
		
		# OpenGL
		libGL
		libGLU

		# GLEW
		glew
	];
}
