# Be sure to restart your server when you modify this file.

# Version of your assets, change this if you want to expire all your assets.
Rails.application.config.assets.version = '1.0'

# Add additional assets to the asset load path
# Rails.application.config.assets.paths << Emoji.images_path

# Precompile additional assets.
# application.js, application.css, and all non-JS/CSS in app/assets folder are already added.
Rails.application.config.assets.precompile += %w( bootstrap.min.css )
Rails.application.config.assets.precompile += %w( font-awesome.min.css )
Rails.application.config.assets.precompile += %w( animate.min.css)
Rails.application.config.assets.precompile += %w( lightbox.css)
Rails.application.config.assets.precompile += %w( main.css)
Rails.application.config.assets.precompile += %w( responsive.css)


Rails.application.config.assets.precompile += %w( html5shiv.js)
Rails.application.config.assets.precompile += %w( respond.js)
Rails.application.config.assets.precompile += %w( jquery.js)
Rails.application.config.assets.precompile += %w( bootstrap.min.js)
Rails.application.config.assets.precompile += %w( lightbox.min.js)
Rails.application.config.assets.precompile += %w( wow.min.js)
Rails.application.config.assets.precompile += %w( main.js)

Rails.application.config.assets.precompile += %w( sweetalert.css)
Rails.application.config.assets.precompile += %w( star-rating.css)
Rails.application.config.assets.precompile += %w( sweetalert.min.js)
Rails.application.config.assets.precompile += %w( jsFunctions.js)
Rails.application.config.assets.precompile += %w( star-rating.js)

Rails.application.config.assets.precompile += %w( style.css)
Rails.application.config.assets.precompile += %w( style-responsive.css)
Rails.application.config.assets.precompile += %w( jquery.backstretch.min.js)


