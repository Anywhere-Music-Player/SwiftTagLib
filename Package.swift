// swift-tools-version: 5.9
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "SwiftTagLib",
    platforms: [
        .iOS(.v17),
        .macOS(.v14),
    ],
    products: [
        .library(
            name: "SwiftTagLib",
            targets: [
                "SwiftTagLib",
                "CxxTagLibBridge",
                "taglib",
            ]
        )
    ],
    targets: [
        .binaryTarget(name: "SwiftTagLib", path: "./XCFrameworkPackage/SwiftTagLib.xcframework"),
        .binaryTarget(name: "CxxTagLibBridge", path: "./XCFrameworkPackage/CxxTagLibBridge.xcframework"),
        .binaryTarget(name: "taglib", path: "./XCFrameworkPackage/taglib.xcframework"),
    ]
)
