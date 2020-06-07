class User < ActiveRecord::Base

 # ##before_save { self.email = email.downcase }
  #validates :name,  presence: true, length: { maximum: 50 }
 # VALID_EMAIL_REGEX = /\A[\w+\-.]+@[a-z\d\-.]+\.[a-z]+\z/i
 # validates :email, presence: true, length: { maximum: 255 },
  #          format: { with: VALID_EMAIL_REGEX },
  #          uniqueness: { case_sensitive: false }
  has_secure_password
  validates :password, presence: true, length: { minimum: 6 }

  validates_presence_of :email, :username, :password
  validates_confirmation_of :password
  validates_uniqueness_of :email, :username

  EMAIL_REGEXP = /\A[^@]+@([^@\.]+\.)+[^@\.]+\z/

  private
  validate do
    errors.add(:email, :invalid) unless email.match(EMAIL_REGEXP)
  end
  # Returns the hash digest of the given string.
 # def User.digest(string)
  #  cost = ActiveModel::SecurePassword.min_cost ? BCrypt::Engine::MIN_COST :
   #     BCrypt::Engine.cost
    #BCrypt::Password.create(string, cost: cost)
    #end


end
