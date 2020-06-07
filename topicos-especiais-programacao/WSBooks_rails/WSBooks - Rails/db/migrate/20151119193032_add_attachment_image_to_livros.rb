class AddAttachmentImageToLivros < ActiveRecord::Migration
  def self.up
    change_table :livros do |t|
      t.attachment :image
    end
  end

  def self.down
    remove_attachment :livros, :image
  end
end
