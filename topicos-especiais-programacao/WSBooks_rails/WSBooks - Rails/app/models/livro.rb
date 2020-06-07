class Livro < ActiveRecord::Base
  has_attached_file :image, styles: { medium: "6000x400", thumb: "200x200" }
  validates_attachment_content_type :image, :content_type => ["image/jpg", "image/jpeg", "image/png", "image/gif"]

  validates_presence_of :titulo, :autor, :editora
  validates_uniqueness_of :titulo
  default_value_for :visita, 0

end
